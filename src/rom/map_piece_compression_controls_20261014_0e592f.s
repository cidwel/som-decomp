.setcpu "65816"
.segment "CODE"
.org $592F
map_control_0e592f:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
