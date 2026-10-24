.setcpu "65816"
.segment "CODE"
.org $53F8
map_control_0e53f8:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
