.setcpu "65816"
.segment "CODE"
.org $5AA4
map_control_0e5aa4:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
