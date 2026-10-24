.setcpu "65816"
.segment "CODE"
.org $6290
map_control_0f6290:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
