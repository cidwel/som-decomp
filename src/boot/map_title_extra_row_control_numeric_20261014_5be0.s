; Actual secondary-row grammar/geometry controls only.
.setcpu "65816"
.segment "RODATA"
.org $5BE0
row_secondary_control_5be0:
    .byte $00 ; row terminator
    .byte $06 ; leading blank count
