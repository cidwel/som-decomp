.setcpu "65816"
.segment "CODE"
.org $32E8
map_control_0e32e8:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
