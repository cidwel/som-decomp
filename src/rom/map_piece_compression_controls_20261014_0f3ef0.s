.setcpu "65816"
.segment "CODE"
.org $3EF0
map_control_0f3ef0:
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
