.setcpu "65816"
.segment "CODE"
.org $1FE1
map_control_0d1fe1:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
