.setcpu "65816"
.segment "CODE"
.org $5782
map_control_0f5782:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
