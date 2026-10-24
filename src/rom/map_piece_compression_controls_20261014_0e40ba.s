.setcpu "65816"
.segment "CODE"
.org $40BA
map_control_0e40ba:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
