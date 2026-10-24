.setcpu "65816"
.segment "CODE"
.org $9BDD
map_control_0d9bdd:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
