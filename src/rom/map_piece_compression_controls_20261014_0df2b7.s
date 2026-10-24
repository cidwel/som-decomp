.setcpu "65816"
.segment "CODE"
.org $F2B7
map_control_0df2b7:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
