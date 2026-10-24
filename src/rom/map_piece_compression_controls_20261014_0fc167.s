.setcpu "65816"
.segment "CODE"
.org $C167
map_control_0fc167:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
