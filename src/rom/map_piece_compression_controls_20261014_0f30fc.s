.setcpu "65816"
.segment "CODE"
.org $30FC
map_control_0f30fc:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
