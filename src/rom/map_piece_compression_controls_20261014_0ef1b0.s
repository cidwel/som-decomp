.setcpu "65816"
.segment "CODE"
.org $F1B0
map_control_0ef1b0:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
