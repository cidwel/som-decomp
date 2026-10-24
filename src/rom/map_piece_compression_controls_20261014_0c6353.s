.setcpu "65816"
.segment "CODE"
.org $6353
map_control_0c6353:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
