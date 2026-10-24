.setcpu "65816"
.segment "CODE"
.org $3A8D
map_control_0c3a8d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
