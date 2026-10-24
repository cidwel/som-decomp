.setcpu "65816"
.segment "CODE"
.org $615C
map_control_0e615c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
