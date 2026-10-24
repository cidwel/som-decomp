.setcpu "65816"
.segment "CODE"
.org $1573
map_control_0f1573:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
