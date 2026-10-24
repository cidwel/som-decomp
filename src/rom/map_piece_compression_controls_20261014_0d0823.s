.setcpu "65816"
.segment "CODE"
.org $0823
map_control_0d0823:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
