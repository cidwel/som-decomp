.setcpu "65816"
.segment "CODE"
.org $69A7
map_control_0e69a7:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
