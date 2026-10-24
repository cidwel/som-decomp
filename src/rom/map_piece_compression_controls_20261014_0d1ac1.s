.setcpu "65816"
.segment "CODE"
.org $1AC1
map_control_0d1ac1:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
