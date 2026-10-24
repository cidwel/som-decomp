.setcpu "65816"
.segment "CODE"
.org $8EB6
map_control_0d8eb6:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
