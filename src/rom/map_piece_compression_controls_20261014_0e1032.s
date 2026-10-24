.setcpu "65816"
.segment "CODE"
.org $1032
map_control_0e1032:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
