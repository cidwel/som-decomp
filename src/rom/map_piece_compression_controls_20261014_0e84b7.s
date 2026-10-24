.setcpu "65816"
.segment "CODE"
.org $84B7
map_control_0e84b7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
