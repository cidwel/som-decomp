.setcpu "65816"
.segment "CODE"
.org $21E2
map_control_0d21e2:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
