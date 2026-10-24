.setcpu "65816"
.segment "CODE"
.org $9FD8
map_control_0d9fd8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
