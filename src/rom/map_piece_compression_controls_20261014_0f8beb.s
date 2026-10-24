.setcpu "65816"
.segment "CODE"
.org $8BEB
map_control_0f8beb:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
