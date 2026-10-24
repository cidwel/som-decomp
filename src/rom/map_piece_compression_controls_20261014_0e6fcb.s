.setcpu "65816"
.segment "CODE"
.org $6FCB
map_control_0e6fcb:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
