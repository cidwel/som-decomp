.setcpu "65816"
.segment "CODE"
.org $BBC2
map_control_0fbbc2:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
