.setcpu "65816"
.segment "CODE"
.org $1987
map_control_0d1987:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
