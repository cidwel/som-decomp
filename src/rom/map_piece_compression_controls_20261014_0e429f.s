.setcpu "65816"
.segment "CODE"
.org $429F
map_control_0e429f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
