.setcpu "65816"
.segment "CODE"
.org $13C2
map_control_0f13c2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
