.setcpu "65816"
.segment "CODE"
.org $2502
map_control_0c2502:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
