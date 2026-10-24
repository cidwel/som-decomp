.setcpu "65816"
.segment "CODE"
.org $8C3B
map_control_0c8c3b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
