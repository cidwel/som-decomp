.setcpu "65816"
.segment "CODE"
.org $6B0E
map_control_0f6b0e:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
