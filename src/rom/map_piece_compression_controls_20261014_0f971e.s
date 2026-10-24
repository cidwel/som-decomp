.setcpu "65816"
.segment "CODE"
.org $971E
map_control_0f971e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
