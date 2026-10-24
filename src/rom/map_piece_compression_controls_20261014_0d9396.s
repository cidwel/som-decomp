.setcpu "65816"
.segment "CODE"
.org $9396
map_control_0d9396:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
