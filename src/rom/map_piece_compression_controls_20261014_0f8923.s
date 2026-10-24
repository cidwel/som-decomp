.setcpu "65816"
.segment "CODE"
.org $8923
map_control_0f8923:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
