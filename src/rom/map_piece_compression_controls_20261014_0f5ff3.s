.setcpu "65816"
.segment "CODE"
.org $5FF3
map_control_0f5ff3:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
