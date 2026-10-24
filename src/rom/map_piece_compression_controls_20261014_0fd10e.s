.setcpu "65816"
.segment "CODE"
.org $D10E
map_control_0fd10e:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
