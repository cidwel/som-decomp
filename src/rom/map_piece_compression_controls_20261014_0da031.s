.setcpu "65816"
.segment "CODE"
.org $A031
map_control_0da031:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
