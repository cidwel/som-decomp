.setcpu "65816"
.segment "CODE"
.org $2821
map_control_0e2821:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
