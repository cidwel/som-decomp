.setcpu "65816"
.segment "CODE"
.org $5CB2
map_control_0f5cb2:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
