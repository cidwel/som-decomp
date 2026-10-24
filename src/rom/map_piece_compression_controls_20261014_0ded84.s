.setcpu "65816"
.segment "CODE"
.org $ED84
map_control_0ded84:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
