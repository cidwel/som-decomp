.setcpu "65816"
.segment "CODE"
.org $7602
map_control_0e7602:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
