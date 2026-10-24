.setcpu "65816"
.segment "CODE"
.org $1B06
map_control_0d1b06:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
