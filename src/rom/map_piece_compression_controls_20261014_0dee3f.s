.setcpu "65816"
.segment "CODE"
.org $EE3F
map_control_0dee3f:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
