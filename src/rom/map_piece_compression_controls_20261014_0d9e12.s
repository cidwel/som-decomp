.setcpu "65816"
.segment "CODE"
.org $9E12
map_control_0d9e12:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
