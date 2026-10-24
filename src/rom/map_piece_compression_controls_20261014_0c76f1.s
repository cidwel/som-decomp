.setcpu "65816"
.segment "CODE"
.org $76F1
map_control_0c76f1:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
