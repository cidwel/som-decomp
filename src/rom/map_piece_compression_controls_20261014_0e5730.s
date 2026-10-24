.setcpu "65816"
.segment "CODE"
.org $5730
map_control_0e5730:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
