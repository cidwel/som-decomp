.setcpu "65816"
.segment "CODE"
.org $E979
map_control_0de979:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
