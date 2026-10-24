.setcpu "65816"
.segment "CODE"
.org $93B2
map_control_0d93b2:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
