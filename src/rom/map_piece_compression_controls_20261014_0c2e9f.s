.setcpu "65816"
.segment "CODE"
.org $2E9F
map_control_0c2e9f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
