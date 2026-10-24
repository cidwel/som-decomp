.setcpu "65816"
.segment "CODE"
.org $99F6
map_control_0d99f6:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
