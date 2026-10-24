.setcpu "65816"
.segment "CODE"
.org $F421
map_control_0ef421:
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
