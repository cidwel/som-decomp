.setcpu "65816"
.segment "CODE"
.org $9E3A
map_control_0e9e3a:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
