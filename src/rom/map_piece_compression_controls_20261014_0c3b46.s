.setcpu "65816"
.segment "CODE"
.org $3B46
map_control_0c3b46:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
