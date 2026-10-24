.setcpu "65816"
.segment "CODE"
.org $5495
map_control_0f5495:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
