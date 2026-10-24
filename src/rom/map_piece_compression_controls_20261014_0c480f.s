.setcpu "65816"
.segment "CODE"
.org $480F
map_control_0c480f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
