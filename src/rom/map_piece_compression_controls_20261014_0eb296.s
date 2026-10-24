.setcpu "65816"
.segment "CODE"
.org $B296
map_control_0eb296:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
