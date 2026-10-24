.setcpu "65816"
.segment "CODE"
.org $B627
map_control_0eb627:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
