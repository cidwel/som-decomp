.setcpu "65816"
.segment "CODE"
.org $8461
map_control_0c8461:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
