.setcpu "65816"
.segment "CODE"
.org $E2DA
map_control_0ee2da:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
