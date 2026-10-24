.setcpu "65816"
.segment "CODE"
.org $FA07
map_control_0efa07:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
