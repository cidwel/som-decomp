.setcpu "65816"
.segment "CODE"
.org $BF0F
map_control_0ebf0f:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
