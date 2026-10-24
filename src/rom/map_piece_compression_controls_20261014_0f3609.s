.setcpu "65816"
.segment "CODE"
.org $3609
map_control_0f3609:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
