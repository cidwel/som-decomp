.setcpu "65816"
.segment "CODE"
.org $DE76
map_control_0ede76:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
