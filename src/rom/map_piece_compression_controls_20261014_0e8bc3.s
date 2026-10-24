.setcpu "65816"
.segment "CODE"
.org $8BC3
map_control_0e8bc3:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
