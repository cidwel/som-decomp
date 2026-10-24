.setcpu "65816"
.segment "CODE"
.org $756B
map_control_0d756b:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
