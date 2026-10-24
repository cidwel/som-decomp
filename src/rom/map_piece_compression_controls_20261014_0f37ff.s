.setcpu "65816"
.segment "CODE"
.org $37FF
map_control_0f37ff:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
