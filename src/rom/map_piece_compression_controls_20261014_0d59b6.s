.setcpu "65816"
.segment "CODE"
.org $59B6
map_control_0d59b6:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
