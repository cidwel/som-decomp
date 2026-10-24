.setcpu "65816"
.segment "CODE"
.org $7BBA
map_control_0c7bba:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
