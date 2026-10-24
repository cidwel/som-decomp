.setcpu "65816"
.segment "CODE"
.org $0CB6
map_control_0c0cb6:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
