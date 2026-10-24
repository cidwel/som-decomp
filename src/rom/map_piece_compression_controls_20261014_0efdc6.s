.setcpu "65816"
.segment "CODE"
.org $FDC6
map_control_0efdc6:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
