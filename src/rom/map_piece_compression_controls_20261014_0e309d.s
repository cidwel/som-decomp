.setcpu "65816"
.segment "CODE"
.org $309D
map_control_0e309d:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
