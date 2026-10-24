.setcpu "65816"
.segment "CODE"
.org $2E3F
map_control_0f2e3f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
