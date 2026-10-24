.setcpu "65816"
.segment "CODE"
.org $420F
map_control_0e420f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
