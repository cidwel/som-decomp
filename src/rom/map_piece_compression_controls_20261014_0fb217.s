.setcpu "65816"
.segment "CODE"
.org $B217
map_control_0fb217:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
