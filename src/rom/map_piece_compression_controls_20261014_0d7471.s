.setcpu "65816"
.segment "CODE"
.org $7471
map_control_0d7471:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
