.setcpu "65816"
.segment "CODE"
.org $C949
map_control_0dc949:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
