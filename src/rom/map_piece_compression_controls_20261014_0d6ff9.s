.setcpu "65816"
.segment "CODE"
.org $6FF9
map_control_0d6ff9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
