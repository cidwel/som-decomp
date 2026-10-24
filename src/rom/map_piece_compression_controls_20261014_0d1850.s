.setcpu "65816"
.segment "CODE"
.org $1850
map_control_0d1850:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
