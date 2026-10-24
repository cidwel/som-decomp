.setcpu "65816"
.segment "CODE"
.org $EBB7
map_control_0eebb7:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
