.setcpu "65816"
.segment "CODE"
.org $F36B
map_control_0cf36b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
