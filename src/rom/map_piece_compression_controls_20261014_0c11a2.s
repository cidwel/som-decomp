.setcpu "65816"
.segment "CODE"
.org $11A2
map_control_0c11a2:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
