.setcpu "65816"
.segment "CODE"
.org $7C7A
map_control_0f7c7a:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
