.setcpu "65816"
.segment "CODE"
.org $2491
map_control_0c2491:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
