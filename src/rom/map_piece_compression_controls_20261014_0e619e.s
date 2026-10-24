.setcpu "65816"
.segment "CODE"
.org $619E
map_control_0e619e:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
