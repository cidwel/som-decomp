.setcpu "65816"
.segment "CODE"
.org $37DA
map_control_0e37da:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
