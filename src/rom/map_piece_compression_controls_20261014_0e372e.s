.setcpu "65816"
.segment "CODE"
.org $372E
map_control_0e372e:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
