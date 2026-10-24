.setcpu "65816"
.segment "CODE"
.org $9396
map_control_0f9396:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
