.setcpu "65816"
.segment "CODE"
.org $3443
map_control_0e3443:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
