.setcpu "65816"
.segment "CODE"
.org $99B0
map_control_0f99b0:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
