.setcpu "65816"
.segment "CODE"
.org $2EF4
map_control_0f2ef4:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
