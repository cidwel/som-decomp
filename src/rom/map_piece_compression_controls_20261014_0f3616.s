.setcpu "65816"
.segment "CODE"
.org $3616
map_control_0f3616:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
