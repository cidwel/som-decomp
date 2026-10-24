.setcpu "65816"
.segment "CODE"
.org $D209
map_control_0fd209:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
