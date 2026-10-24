.setcpu "65816"
.segment "CODE"
.org $13FE
map_control_0c13fe:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
