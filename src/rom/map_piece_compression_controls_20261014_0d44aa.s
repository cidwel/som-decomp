.setcpu "65816"
.segment "CODE"
.org $44AA
map_control_0d44aa:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
