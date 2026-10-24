.setcpu "65816"
.segment "CODE"
.org $E0E8
map_control_0de0e8:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
