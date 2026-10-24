.setcpu "65816"
.segment "CODE"
.org $D645
map_control_0fd645:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
