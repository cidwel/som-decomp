.setcpu "65816"
.segment "CODE"
.org $AC8F
map_control_0eac8f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
