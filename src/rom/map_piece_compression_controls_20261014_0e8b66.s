.setcpu "65816"
.segment "CODE"
.org $8B66
map_control_0e8b66:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
