.setcpu "65816"
.segment "CODE"
.org $8BDD
map_control_0f8bdd:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
