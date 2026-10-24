.setcpu "65816"
.segment "CODE"
.org $0A70
map_control_0e0a70:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
