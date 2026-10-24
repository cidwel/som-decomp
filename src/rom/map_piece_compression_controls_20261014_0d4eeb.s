.setcpu "65816"
.segment "CODE"
.org $4EEB
map_control_0d4eeb:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
