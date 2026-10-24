.setcpu "65816"
.segment "CODE"
.org $EC13
map_control_0fec13:
    .byte $EF ; backreference distance high bits
    .byte $12 ; distance low bit/count
