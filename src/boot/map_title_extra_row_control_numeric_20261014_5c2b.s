; Actual secondary-row grammar/geometry controls only.
.setcpu "65816"
.segment "RODATA"
.org $5C2B
row_secondary_control_5c2b:
    .byte $00 ; row terminator
    .byte $05 ; leading blank count
