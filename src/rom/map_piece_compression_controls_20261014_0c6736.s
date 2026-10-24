.setcpu "65816"
.segment "CODE"
.org $6736
map_control_0c6736:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
