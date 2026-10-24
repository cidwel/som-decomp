.setcpu "65816"
.segment "CODE"
.org $7468
map_control_0d7468:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
