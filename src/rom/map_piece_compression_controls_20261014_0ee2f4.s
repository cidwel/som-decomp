.setcpu "65816"
.segment "CODE"
.org $E2F4
map_control_0ee2f4:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
