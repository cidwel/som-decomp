.setcpu "65816"
.segment "CODE"
.org $38EB
map_control_0f38eb:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
