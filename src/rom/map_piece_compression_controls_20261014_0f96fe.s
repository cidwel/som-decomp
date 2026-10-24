.setcpu "65816"
.segment "CODE"
.org $96FE
map_control_0f96fe:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
