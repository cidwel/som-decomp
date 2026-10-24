.setcpu "65816"
.segment "CODE"
.org $9288
map_control_0c9288:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
