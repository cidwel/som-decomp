.setcpu "65816"
.segment "CODE"
.org $C114
map_control_0ec114:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
