; Actual secondary-row grammar/geometry controls only.
.setcpu "65816"
.segment "RODATA"
.org $5B96
row_secondary_control_5b96:
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $03 ; leading blank count
