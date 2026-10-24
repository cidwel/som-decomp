.setcpu "65816"
.segment "CODE"
.org $17E0
map_control_0e17e0:
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
