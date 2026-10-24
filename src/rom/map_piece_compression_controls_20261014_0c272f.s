.setcpu "65816"
.segment "CODE"
.org $272F
map_control_0c272f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
