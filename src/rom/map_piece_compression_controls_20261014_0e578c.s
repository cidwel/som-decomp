.setcpu "65816"
.segment "CODE"
.org $578C
map_control_0e578c:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
