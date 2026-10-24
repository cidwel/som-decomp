.setcpu "65816"
.segment "CODE"
.org $25E9
map_control_0d25e9:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
