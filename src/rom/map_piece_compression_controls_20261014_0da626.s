.setcpu "65816"
.segment "CODE"
.org $A626
map_control_0da626:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
