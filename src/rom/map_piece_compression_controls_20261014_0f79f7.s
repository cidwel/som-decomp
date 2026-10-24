.setcpu "65816"
.segment "CODE"
.org $79F7
map_control_0f79f7:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
