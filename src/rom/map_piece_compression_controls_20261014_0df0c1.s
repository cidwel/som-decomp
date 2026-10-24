.setcpu "65816"
.segment "CODE"
.org $F0C1
map_control_0df0c1:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
