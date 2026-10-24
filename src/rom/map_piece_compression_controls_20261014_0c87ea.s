.setcpu "65816"
.segment "CODE"
.org $87EA
map_control_0c87ea:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
