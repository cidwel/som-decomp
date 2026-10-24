.setcpu "65816"
.segment "CODE"
.org $CDA7
map_control_0ecda7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
