.setcpu "65816"
.segment "CODE"
.org $37C5
map_control_0f37c5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
