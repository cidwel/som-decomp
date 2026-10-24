.setcpu "65816"
.segment "CODE"
.org $87D9
map_control_0f87d9:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
