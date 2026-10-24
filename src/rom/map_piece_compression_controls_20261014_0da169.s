.setcpu "65816"
.segment "CODE"
.org $A169
map_control_0da169:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
