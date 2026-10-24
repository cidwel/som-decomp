.setcpu "65816"
.segment "CODE"
.org $CEB4
map_control_0fceb4:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
