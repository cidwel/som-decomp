.setcpu "65816"
.segment "CODE"
.org $CC94
map_control_0dcc94:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
