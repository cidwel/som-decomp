.setcpu "65816"
.segment "CODE"
.org $4036
map_control_0e4036:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
