.setcpu "65816"
.segment "CODE"
.org $1496
map_control_0e1496:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
