.setcpu "65816"
.segment "CODE"
.org $0C0C
map_control_0e0c0c:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
