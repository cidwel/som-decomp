.setcpu "65816"
.segment "CODE"
.org $EB8F
map_control_0eeb8f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
