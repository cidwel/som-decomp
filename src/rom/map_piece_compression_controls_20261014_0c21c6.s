.setcpu "65816"
.segment "CODE"
.org $21C6
map_control_0c21c6:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
