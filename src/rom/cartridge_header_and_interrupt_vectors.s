; Cartridge metadata and bank-zero interrupt destinations, C0:FFC0..FFFF.
.setcpu "65816"
.segment "RODATA"
.org $FFC0
cartridge_header:
    .byte "Secret of MANA       "
    .byte $21                  ; HiROM mapping
    .byte $02                  ; ROM, RAM and battery
    .byte $0B, $03             ; ROM and SRAM size exponents
    .byte $01, $C3, $00        ; Region, publisher and revision
    .word $AE03, $51FC         ; Checksum complement and checksum
native_interrupt_vectors:
    .word $FFFF, $FFFF
    .word $FFFF, $FFFF, $FFFF  ; COP, BRK and ABORT
    .word $0100, $8004, $0104  ; NMI, reserved and IRQ
emulation_interrupt_vectors:
    .word $0000, $0000
    .word $0000, $0000, $0000  ; COP, reserved and ABORT
    .word $0000, $8004, $FFFF  ; NMI, reset and IRQ/BRK
