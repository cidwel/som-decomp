.setcpu "65816"
.segment "CODE"
.org $72E9
map_control_0f72e9:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
