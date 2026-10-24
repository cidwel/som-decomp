.setcpu "65816"
.segment "CODE"
.org $F786
map_control_0cf786:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
