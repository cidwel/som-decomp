.setcpu "65816"
.segment "CODE"
.org $82F1
map_control_0c82f1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
