.setcpu "65816"
.segment "CODE"
.org $9E3C
map_control_0d9e3c:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
