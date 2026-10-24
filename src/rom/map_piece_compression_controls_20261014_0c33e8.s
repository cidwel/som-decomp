.setcpu "65816"
.segment "CODE"
.org $33E8
map_control_0c33e8:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
