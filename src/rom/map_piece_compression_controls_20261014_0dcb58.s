.setcpu "65816"
.segment "CODE"
.org $CB58
map_control_0dcb58:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
