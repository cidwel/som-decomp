.setcpu "65816"
.segment "CODE"
.org $D453
map_control_0dd453:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
