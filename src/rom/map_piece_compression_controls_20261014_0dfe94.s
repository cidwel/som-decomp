.setcpu "65816"
.segment "CODE"
.org $FE94
map_control_0dfe94:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
