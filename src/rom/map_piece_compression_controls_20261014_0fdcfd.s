.setcpu "65816"
.segment "CODE"
.org $DCFD
map_control_0fdcfd:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
