.setcpu "65816"
.segment "CODE"
.org $60B9
map_control_0d60b9:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
