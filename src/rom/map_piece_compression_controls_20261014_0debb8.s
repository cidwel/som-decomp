.setcpu "65816"
.segment "CODE"
.org $EBB8
map_control_0debb8:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
