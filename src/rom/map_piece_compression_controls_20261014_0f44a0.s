.setcpu "65816"
.segment "CODE"
.org $44A0
map_control_0f44a0:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
