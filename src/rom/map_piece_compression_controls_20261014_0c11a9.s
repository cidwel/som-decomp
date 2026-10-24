.setcpu "65816"
.segment "CODE"
.org $11A9
map_control_0c11a9:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
