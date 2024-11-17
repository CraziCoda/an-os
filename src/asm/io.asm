global outb

; outb - send a byte to an I/O port
; stack:    [esp + 8] the data byte
;           [esp + 4] the I/O port
;           [esp] return address

outb:
    mov     al,     [esp + 8]                   ; the data byte
    mov     dx,     [esp + 4]                   ; address port
    out     dx,     al                          ; send the data to I/O port
    ret
