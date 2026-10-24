.setcpu "65816"
.segment "CODE"
.org $96AA
map_control_0f96aa:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
