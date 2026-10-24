.setcpu "65816"
.segment "CODE"
.org $468F
map_control_0d468f:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
