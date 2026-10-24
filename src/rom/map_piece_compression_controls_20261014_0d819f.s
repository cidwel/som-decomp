.setcpu "65816"
.segment "CODE"
.org $819F
map_control_0d819f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
