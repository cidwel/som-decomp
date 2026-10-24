.setcpu "65816"
.segment "CODE"
.org $EE4F
map_control_0dee4f:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
