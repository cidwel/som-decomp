.setcpu "65816"
.segment "CODE"
.org $4255
map_control_0c4255:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
