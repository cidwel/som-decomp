.setcpu "65816"
.segment "CODE"
.org $7CA0
map_control_0e7ca0:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
