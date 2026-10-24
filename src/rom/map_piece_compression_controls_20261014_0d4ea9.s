.setcpu "65816"
.segment "CODE"
.org $4EA9
map_control_0d4ea9:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
