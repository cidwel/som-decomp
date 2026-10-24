.setcpu "65816"
.segment "CODE"
.org $2574
map_control_0c2574:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
