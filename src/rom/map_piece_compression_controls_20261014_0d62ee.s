.setcpu "65816"
.segment "CODE"
.org $62EE
map_control_0d62ee:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
