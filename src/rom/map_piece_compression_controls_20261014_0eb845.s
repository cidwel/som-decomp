.setcpu "65816"
.segment "CODE"
.org $B845
map_control_0eb845:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
