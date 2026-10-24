.setcpu "65816"
.segment "CODE"
.org $40D7
map_control_0c40d7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
