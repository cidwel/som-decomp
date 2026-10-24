.setcpu "65816"
.segment "CODE"
.org $48D1
map_control_0c48d1:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
