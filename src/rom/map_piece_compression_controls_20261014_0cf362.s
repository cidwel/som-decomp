.setcpu "65816"
.segment "CODE"
.org $F362
map_control_0cf362:
    .byte $E0 ; previous-row copy escape
    .byte $B9 ; row-distance/count
