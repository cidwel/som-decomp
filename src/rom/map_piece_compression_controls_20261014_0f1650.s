.setcpu "65816"
.segment "CODE"
.org $1650
map_control_0f1650:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
