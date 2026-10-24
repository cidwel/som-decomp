.setcpu "65816"
.segment "CODE"
.org $0110
map_control_0f0110:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
