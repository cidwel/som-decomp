.setcpu "65816"
.segment "CODE"
.org $FA15
map_control_0dfa15:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
