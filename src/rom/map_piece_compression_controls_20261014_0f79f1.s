.setcpu "65816"
.segment "CODE"
.org $79F1
map_control_0f79f1:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
