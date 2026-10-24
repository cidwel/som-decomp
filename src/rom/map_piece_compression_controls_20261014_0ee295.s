.setcpu "65816"
.segment "CODE"
.org $E295
map_control_0ee295:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
