.setcpu "65816"
.segment "CODE"
.org $17F1
map_control_0f17f1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
