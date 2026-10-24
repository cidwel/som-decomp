.setcpu "65816"
.segment "CODE"
.org $8ED1
map_control_0c8ed1:
    .byte $F5 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $F1 ; progressive-copy count
