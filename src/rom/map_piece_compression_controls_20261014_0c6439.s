.setcpu "65816"
.segment "CODE"
.org $6439
map_control_0c6439:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
