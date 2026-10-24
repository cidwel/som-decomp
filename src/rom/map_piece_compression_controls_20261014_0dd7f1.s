.setcpu "65816"
.segment "CODE"
.org $D7F1
map_control_0dd7f1:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
