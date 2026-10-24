.setcpu "65816"
.segment "CODE"
.org $F43A
map_control_0ef43a:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
