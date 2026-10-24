.setcpu "65816"
.segment "CODE"
.org $B91A
map_control_0fb91a:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
