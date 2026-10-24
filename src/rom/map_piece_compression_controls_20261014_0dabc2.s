.setcpu "65816"
.segment "CODE"
.org $ABC2
map_control_0dabc2:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
