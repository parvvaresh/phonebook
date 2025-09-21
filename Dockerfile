# Build stage
FROM golang:1.23 AS builder

WORKDIR /app

# Copy go.mod (only needed if you have go.mod)
COPY go.mod ./
RUN go mod tidy || true

# Copy source code
COPY . .

# Build the app
RUN go build -o taskmanager main.go

# Final stage
FROM debian:bullseye-slim

WORKDIR /root/

COPY --from=builder /app/taskmanager .

# Default command -> run "list"
CMD ["./taskmanager", "list"]
