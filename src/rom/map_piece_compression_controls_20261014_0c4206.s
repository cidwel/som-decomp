.setcpu "65816"
.segment "CODE"
.org $4206
map_control_0c4206:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
