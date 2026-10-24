.setcpu "65816"
.segment "CODE"
.org $7308
map_control_0c7308:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
