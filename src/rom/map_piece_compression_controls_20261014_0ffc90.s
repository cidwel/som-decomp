.setcpu "65816"
.segment "CODE"
.org $FC90
map_control_0ffc90:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
