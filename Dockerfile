# Use official Golang image as the build stage
FROM golang:1.23 AS builder

WORKDIR /app

# Copy go mod and sum files
COPY go.mod go.sum ./
RUN go mod download

# Copy the source code
COPY . .

# Build the Go app
RUN go build -o taskmanager main.go

# Final lightweight image
FROM debian:bullseye-slim

WORKDIR /root/

COPY --from=builder /app/taskmanager .

# Default command
CMD ["./taskmanager", "list"]
