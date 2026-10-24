.setcpu "65816"
.segment "CODE"
.org $004F
map_control_0f004f:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
