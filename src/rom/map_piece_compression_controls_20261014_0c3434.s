.setcpu "65816"
.segment "CODE"
.org $3434
map_control_0c3434:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
