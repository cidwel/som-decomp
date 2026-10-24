.setcpu "65816"
.segment "CODE"
.org $62B9
map_control_0e62b9:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
