.setcpu "65816"
.segment "CODE"
.org $526F
map_control_0c526f:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
