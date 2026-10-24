.setcpu "65816"
.segment "CODE"
.org $CA08
map_control_0eca08:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
