.setcpu "65816"
.segment "CODE"
.org $B1AF
map_control_0db1af:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
