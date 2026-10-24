.setcpu "65816"
.segment "CODE"
.org $E913
map_control_0de913:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
