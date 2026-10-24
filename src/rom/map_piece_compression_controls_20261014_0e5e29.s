.setcpu "65816"
.segment "CODE"
.org $5E29
map_control_0e5e29:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
