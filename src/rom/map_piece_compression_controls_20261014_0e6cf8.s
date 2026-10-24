.setcpu "65816"
.segment "CODE"
.org $6CF8
map_control_0e6cf8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
