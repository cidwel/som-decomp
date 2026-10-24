.setcpu "65816"
.segment "CODE"
.org $5ED7
map_control_0c5ed7:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
