.setcpu "65816"
.segment "CODE"
.org $81F1
map_control_0e81f1:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
