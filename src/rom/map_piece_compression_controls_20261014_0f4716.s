.setcpu "65816"
.segment "CODE"
.org $4716
map_control_0f4716:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
