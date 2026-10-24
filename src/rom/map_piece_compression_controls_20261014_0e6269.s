.setcpu "65816"
.segment "CODE"
.org $6269
map_control_0e6269:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
