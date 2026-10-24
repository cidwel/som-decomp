.setcpu "65816"
.segment "CODE"
.org $C5B2
map_control_0ec5b2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
