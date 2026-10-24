.setcpu "65816"
.segment "CODE"
.org $94C1
map_control_0f94c1:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
