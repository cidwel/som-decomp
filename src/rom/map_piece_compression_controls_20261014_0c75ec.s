.setcpu "65816"
.segment "CODE"
.org $75EC
map_control_0c75ec:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
