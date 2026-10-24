.setcpu "65816"
.segment "CODE"
.org $438F
map_control_0f438f:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
