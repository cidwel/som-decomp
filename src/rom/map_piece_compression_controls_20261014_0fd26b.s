.setcpu "65816"
.segment "CODE"
.org $D26B
map_control_0fd26b:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
