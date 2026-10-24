.setcpu "65816"
.segment "CODE"
.org $617A
map_control_0e617a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
