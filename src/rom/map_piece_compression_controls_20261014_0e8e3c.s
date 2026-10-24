.setcpu "65816"
.segment "CODE"
.org $8E3C
map_control_0e8e3c:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
