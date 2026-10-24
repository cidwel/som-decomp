.setcpu "65816"
.segment "CODE"
.org $ACCB
map_control_0daccb:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
