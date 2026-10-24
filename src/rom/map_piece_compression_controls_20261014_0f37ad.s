.setcpu "65816"
.segment "CODE"
.org $37AD
map_control_0f37ad:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
