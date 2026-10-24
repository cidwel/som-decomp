.setcpu "65816"
.segment "CODE"
.org $596D
map_control_0e596d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
