.setcpu "65816"
.segment "CODE"
.org $DFF2
map_control_0fdff2:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
