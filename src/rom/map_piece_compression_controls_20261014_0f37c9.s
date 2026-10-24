.setcpu "65816"
.segment "CODE"
.org $37C9
map_control_0f37c9:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
