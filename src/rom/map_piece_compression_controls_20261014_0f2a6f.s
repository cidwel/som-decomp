.setcpu "65816"
.segment "CODE"
.org $2A6F
map_control_0f2a6f:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
