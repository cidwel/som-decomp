.setcpu "65816"
.segment "CODE"
.org $9566
map_control_0f9566:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
