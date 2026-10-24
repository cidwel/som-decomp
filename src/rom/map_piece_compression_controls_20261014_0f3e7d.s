.setcpu "65816"
.segment "CODE"
.org $3E7D
map_control_0f3e7d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
