.setcpu "65816"
.segment "CODE"
.org $ACD7
map_control_0dacd7:
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
