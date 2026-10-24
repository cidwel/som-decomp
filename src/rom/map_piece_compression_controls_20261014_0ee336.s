.setcpu "65816"
.segment "CODE"
.org $E336
map_control_0ee336:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
