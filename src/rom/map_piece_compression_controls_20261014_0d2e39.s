.setcpu "65816"
.segment "CODE"
.org $2E39
map_control_0d2e39:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
