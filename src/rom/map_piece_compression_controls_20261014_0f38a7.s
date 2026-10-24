.setcpu "65816"
.segment "CODE"
.org $38A7
map_control_0f38a7:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
