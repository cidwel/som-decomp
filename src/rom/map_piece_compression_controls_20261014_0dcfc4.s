.setcpu "65816"
.segment "CODE"
.org $CFC4
map_control_0dcfc4:
    .byte $E0 ; previous-row copy escape
    .byte $76 ; row-distance/count
