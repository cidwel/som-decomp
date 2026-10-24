.setcpu "65816"
.segment "CODE"
.org $CDB7
map_control_0dcdb7:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
