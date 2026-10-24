.setcpu "65816"
.segment "CODE"
.org $F50D
map_control_0cf50d:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
