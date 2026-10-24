.setcpu "65816"
.segment "CODE"
.org $D349
map_control_0dd349:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
