.setcpu "65816"
.segment "CODE"
.org $10FE
map_control_0d10fe:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
