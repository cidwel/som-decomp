.setcpu "65816"
.segment "CODE"
.org $8C83
map_control_0f8c83:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
