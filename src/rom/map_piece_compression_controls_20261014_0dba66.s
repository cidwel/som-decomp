.setcpu "65816"
.segment "CODE"
.org $BA66
map_control_0dba66:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
