.setcpu "65816"
.segment "CODE"
.org $7EE6
map_control_0d7ee6:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
