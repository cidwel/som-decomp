.setcpu "65816"
.segment "CODE"
.org $597C
map_control_0e597c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
