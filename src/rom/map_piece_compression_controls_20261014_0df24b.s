.setcpu "65816"
.segment "CODE"
.org $F24B
map_control_0df24b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
