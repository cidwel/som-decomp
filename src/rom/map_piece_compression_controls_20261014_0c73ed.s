.setcpu "65816"
.segment "CODE"
.org $73ED
map_control_0c73ed:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
