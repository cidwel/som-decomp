.setcpu "65816"
.segment "CODE"
.org $9FAF
map_control_0d9faf:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
