.setcpu "65816"
.segment "CODE"
.org $6F61
map_control_0c6f61:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
