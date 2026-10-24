.setcpu "65816"
.segment "CODE"
.org $0C1B
map_control_0e0c1b:
    .byte $E7 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
