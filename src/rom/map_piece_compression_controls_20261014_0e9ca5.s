.setcpu "65816"
.segment "CODE"
.org $9CA5
map_control_0e9ca5:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
