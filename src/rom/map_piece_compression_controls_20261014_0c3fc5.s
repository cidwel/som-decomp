.setcpu "65816"
.segment "CODE"
.org $3FC5
map_control_0c3fc5:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
