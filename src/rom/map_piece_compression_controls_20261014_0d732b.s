.setcpu "65816"
.segment "CODE"
.org $732B
map_control_0d732b:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
