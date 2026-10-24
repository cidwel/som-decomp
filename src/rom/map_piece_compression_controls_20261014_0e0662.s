.setcpu "65816"
.segment "CODE"
.org $0662
map_control_0e0662:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
