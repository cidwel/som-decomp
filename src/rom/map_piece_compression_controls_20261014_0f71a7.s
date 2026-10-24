.setcpu "65816"
.segment "CODE"
.org $71A7
map_control_0f71a7:
    .byte $E8 ; backreference distance high bits
    .byte $4A ; distance low bit/count
