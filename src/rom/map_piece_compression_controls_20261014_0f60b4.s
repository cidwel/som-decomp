.setcpu "65816"
.segment "CODE"
.org $60B4
map_control_0f60b4:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
