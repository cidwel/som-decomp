.setcpu "65816"
.segment "CODE"
.org $82FF
map_control_0d82ff:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
