; Actual secondary-row grammar/geometry controls only.
.setcpu "65816"
.segment "RODATA"
.org $5BCA
row_secondary_control_5bca:
    .byte $00 ; row terminator
    .byte $06 ; leading blank count
