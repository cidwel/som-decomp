.setcpu "65816"
.segment "CODE"
.org $1B22
map_control_0f1b22:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $C2 ; row-distance/count
