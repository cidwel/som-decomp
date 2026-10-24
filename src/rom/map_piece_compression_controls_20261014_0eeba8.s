.setcpu "65816"
.segment "CODE"
.org $EBA8
map_control_0eeba8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
