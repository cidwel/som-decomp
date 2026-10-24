.setcpu "65816"
.segment "CODE"
.org $E27C
map_control_0ee27c:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
