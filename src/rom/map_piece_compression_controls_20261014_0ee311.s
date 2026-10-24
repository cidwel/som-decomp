.setcpu "65816"
.segment "CODE"
.org $E311
map_control_0ee311:
    .byte $E1 ; previous-row copy count
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
