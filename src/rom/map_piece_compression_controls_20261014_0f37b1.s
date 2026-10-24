.setcpu "65816"
.segment "CODE"
.org $37B1
map_control_0f37b1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
