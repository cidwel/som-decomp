.setcpu "65816"
.segment "CODE"
.org $550E
map_control_0f550e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
