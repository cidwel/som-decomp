.setcpu "65816"
.segment "CODE"
.org $609C
map_control_0d609c:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
