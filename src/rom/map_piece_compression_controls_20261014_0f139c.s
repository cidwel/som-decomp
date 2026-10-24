.setcpu "65816"
.segment "CODE"
.org $139C
map_control_0f139c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
