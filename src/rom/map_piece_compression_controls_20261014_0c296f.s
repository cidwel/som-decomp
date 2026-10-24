.setcpu "65816"
.segment "CODE"
.org $296F
map_control_0c296f:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
