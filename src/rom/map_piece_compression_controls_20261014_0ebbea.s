.setcpu "65816"
.segment "CODE"
.org $BBEA
map_control_0ebbea:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
