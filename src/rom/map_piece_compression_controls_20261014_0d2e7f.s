.setcpu "65816"
.segment "CODE"
.org $2E7F
map_control_0d2e7f:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
