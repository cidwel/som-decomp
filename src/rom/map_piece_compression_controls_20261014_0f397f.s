.setcpu "65816"
.segment "CODE"
.org $397F
map_control_0f397f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
