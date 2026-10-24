.setcpu "65816"
.segment "CODE"
.org $FC3C
map_control_0dfc3c:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
