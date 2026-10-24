.setcpu "65816"
.segment "CODE"
.org $48A3
map_control_0c48a3:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
