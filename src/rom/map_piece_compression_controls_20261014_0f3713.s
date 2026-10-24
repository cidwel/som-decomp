.setcpu "65816"
.segment "CODE"
.org $3713
map_control_0f3713:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
