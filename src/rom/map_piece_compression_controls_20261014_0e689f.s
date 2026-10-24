.setcpu "65816"
.segment "CODE"
.org $689F
map_control_0e689f:
    .byte $E0 ; previous-row copy escape
    .byte $76 ; row-distance/count
