.setcpu "65816"
.segment "CODE"
.org $717F
map_control_0d717f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
