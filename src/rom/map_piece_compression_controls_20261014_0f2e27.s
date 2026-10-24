.setcpu "65816"
.segment "CODE"
.org $2E27
map_control_0f2e27:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
