.setcpu "65816"
.segment "CODE"
.org $4821
map_control_0d4821:
    .byte $E8 ; backreference distance high bits
    .byte $9E ; distance low bit/count
