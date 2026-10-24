; Native row syntax/geometry controls only: no glyph bytes or strings.
.setcpu "65816"
.segment "RODATA"
.org $5A55
row_control_5a55:
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $04 ; leading blank count
