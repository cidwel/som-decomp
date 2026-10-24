.setcpu "65816"
.segment "CODE"
.org $43A6
map_control_0e43a6:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
