.setcpu "65816"
.segment "CODE"
.org $21ED
map_control_0c21ed:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
