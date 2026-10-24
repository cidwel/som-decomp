.setcpu "65816"
.segment "CODE"
.org $9207
map_control_0e9207:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
