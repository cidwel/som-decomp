.setcpu "65816"
.segment "CODE"
.org $2489
map_control_0e2489:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
