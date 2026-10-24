.setcpu "65816"
.segment "CODE"
.org $968A
map_control_0f968a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
