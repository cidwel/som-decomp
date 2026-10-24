.setcpu "65816"
.segment "CODE"
.org $53B6
map_control_0e53b6:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
