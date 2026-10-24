.setcpu "65816"
.segment "CODE"
.org $60AC
map_control_0c60ac:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
