.setcpu "65816"
.segment "CODE"
.org $0ECF
map_control_0d0ecf:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
