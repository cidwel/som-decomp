.setcpu "65816"
.segment "CODE"
.org $5FCF
map_control_0d5fcf:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
