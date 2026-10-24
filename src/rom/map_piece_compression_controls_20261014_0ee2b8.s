.setcpu "65816"
.segment "CODE"
.org $E2B8
map_control_0ee2b8:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
