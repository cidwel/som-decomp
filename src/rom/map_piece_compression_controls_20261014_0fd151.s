.setcpu "65816"
.segment "CODE"
.org $D151
map_control_0fd151:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
