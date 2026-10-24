.setcpu "65816"
.segment "CODE"
.org $51BA
map_control_0e51ba:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
