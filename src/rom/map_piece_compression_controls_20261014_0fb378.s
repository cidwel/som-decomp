.setcpu "65816"
.segment "CODE"
.org $B378
map_control_0fb378:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
