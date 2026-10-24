.setcpu "65816"
.segment "CODE"
.org $17EC
map_control_0e17ec:
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
