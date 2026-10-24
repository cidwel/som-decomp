.setcpu "65816"
.segment "CODE"
.org $4E15
map_control_0d4e15:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
