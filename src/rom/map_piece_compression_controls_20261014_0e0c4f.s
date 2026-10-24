.setcpu "65816"
.segment "CODE"
.org $0C4F
map_control_0e0c4f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
