.setcpu "65816"
.segment "CODE"
.org $85A7
map_control_0f85a7:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
