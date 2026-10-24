.setcpu "65816"
.segment "CODE"
.org $133F
map_control_0d133f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
