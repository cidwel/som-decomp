.setcpu "65816"
.segment "CODE"
.org $6321
map_control_0e6321:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
