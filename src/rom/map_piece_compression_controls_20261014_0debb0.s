.setcpu "65816"
.segment "CODE"
.org $EBB0
map_control_0debb0:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
