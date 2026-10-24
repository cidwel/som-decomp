.setcpu "65816"
.segment "CODE"
.org $879C
map_control_0c879c:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
