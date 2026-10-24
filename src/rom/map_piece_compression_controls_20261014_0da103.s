.setcpu "65816"
.segment "CODE"
.org $A103
map_control_0da103:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
