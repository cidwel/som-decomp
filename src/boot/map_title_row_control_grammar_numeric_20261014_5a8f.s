; Native row syntax/geometry controls only: no glyph bytes or strings.
.setcpu "65816"
.segment "RODATA"
.org $5A8F
row_control_5a8f:
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $05 ; leading blank count
