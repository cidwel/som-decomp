.setcpu "65816"
.segment "CODE"
.org $795B
map_control_0f795b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
