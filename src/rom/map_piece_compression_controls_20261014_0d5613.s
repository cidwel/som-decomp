.setcpu "65816"
.segment "CODE"
.org $5613
map_control_0d5613:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
