.setcpu "65816"
.segment "CODE"
.org $D04F
map_control_0fd04f:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
