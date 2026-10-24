.setcpu "65816"
.segment "CODE"
.org $FCD6
map_control_0dfcd6:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
