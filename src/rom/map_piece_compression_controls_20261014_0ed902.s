.setcpu "65816"
.segment "CODE"
.org $D902
map_control_0ed902:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
