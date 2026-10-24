.setcpu "65816"
.segment "CODE"
.org $32DA
map_control_0e32da:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
