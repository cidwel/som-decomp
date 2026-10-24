.setcpu "65816"
.segment "CODE"
.org $0EDB
map_control_0d0edb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
