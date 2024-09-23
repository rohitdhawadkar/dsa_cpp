    .section .data
msg:    .asciz "Hello, World!\n"

    .section .text
    .global _start

_start:
    mov x0, 1                // File descriptor (stdout)
    ldr x1, =msg             // Pointer to the message
    ldr x2, =13              // Length of the message
    mov x8, 64               // System call number for write
    svc 0                    // Invoke the system call

    mov x8, 93               // System call number for exit
    mov x0, 0                // Exit code
    svc 0                    // Invoke the system call
