.setcpu "65816"
.segment "CODE"
.org $2451
map_control_0e2451:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
