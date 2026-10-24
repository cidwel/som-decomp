.setcpu "65816"
.segment "CODE"
.org $7A65
map_control_0c7a65:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
