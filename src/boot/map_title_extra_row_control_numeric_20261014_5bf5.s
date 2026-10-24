; Actual secondary-row grammar/geometry controls only.
.setcpu "65816"
.segment "RODATA"
.org $5BF5
row_secondary_control_5bf5:
    .byte $00 ; row terminator
    .byte $06 ; leading blank count
