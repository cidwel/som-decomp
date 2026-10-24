.setcpu "65816"
.segment "CODE"
.org $4DA6
map_control_0e4da6:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
