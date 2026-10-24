; Native row syntax/geometry controls only: no glyph bytes or strings.
.setcpu "65816"
.segment "RODATA"
.org $5B2B
row_control_5b2b:
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $07 ; leading blank count
