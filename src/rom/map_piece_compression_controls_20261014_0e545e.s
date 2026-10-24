.setcpu "65816"
.segment "CODE"
.org $545E
map_control_0e545e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
