.setcpu "65816"
.segment "CODE"
.org $9BC2
map_control_0f9bc2:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
