.setcpu "65816"
.segment "CODE"
.org $9E6A
map_control_0e9e6a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
