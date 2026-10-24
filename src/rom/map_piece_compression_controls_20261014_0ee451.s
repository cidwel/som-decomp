.setcpu "65816"
.segment "CODE"
.org $E451
map_control_0ee451:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
