.setcpu "65816"
.segment "CODE"
.org $7F8F
map_control_0c7f8f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
