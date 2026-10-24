.setcpu "65816"
.segment "CODE"
.org $566D
map_control_0e566d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
