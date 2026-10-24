.setcpu "65816"
.segment "CODE"
.org $620D
map_control_0e620d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
