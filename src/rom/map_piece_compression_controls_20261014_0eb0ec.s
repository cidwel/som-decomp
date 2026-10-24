.setcpu "65816"
.segment "CODE"
.org $B0EC
map_control_0eb0ec:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
