.setcpu "65816"
.segment "CODE"
.org $3244
map_control_0c3244:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
