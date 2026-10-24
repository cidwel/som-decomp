.setcpu "65816"
.segment "CODE"
.org $CFA7
map_control_0dcfa7:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
