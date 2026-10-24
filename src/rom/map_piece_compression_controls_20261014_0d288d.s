.setcpu "65816"
.segment "CODE"
.org $288D
map_control_0d288d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
