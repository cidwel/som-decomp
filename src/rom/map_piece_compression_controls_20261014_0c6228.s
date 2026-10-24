.setcpu "65816"
.segment "CODE"
.org $6228
map_control_0c6228:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
