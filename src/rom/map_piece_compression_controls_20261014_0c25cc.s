.setcpu "65816"
.segment "CODE"
.org $25CC
map_control_0c25cc:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
