.setcpu "65816"
.segment "CODE"
.org $DAE5
map_control_0fdae5:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
