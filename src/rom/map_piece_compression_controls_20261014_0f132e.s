.setcpu "65816"
.segment "CODE"
.org $132E
map_control_0f132e:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
