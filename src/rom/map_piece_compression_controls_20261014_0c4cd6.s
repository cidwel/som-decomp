.setcpu "65816"
.segment "CODE"
.org $4CD6
map_control_0c4cd6:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
