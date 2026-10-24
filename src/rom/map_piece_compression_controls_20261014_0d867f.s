.setcpu "65816"
.segment "CODE"
.org $867F
map_control_0d867f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
