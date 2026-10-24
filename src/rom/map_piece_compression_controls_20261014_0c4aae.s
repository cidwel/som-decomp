.setcpu "65816"
.segment "CODE"
.org $4AAE
map_control_0c4aae:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
