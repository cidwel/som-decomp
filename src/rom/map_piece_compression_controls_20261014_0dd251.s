.setcpu "65816"
.segment "CODE"
.org $D251
map_control_0dd251:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
