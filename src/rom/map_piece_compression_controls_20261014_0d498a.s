.setcpu "65816"
.segment "CODE"
.org $498A
map_control_0d498a:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
