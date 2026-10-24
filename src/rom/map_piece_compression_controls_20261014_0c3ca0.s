.setcpu "65816"
.segment "CODE"
.org $3CA0
map_control_0c3ca0:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
