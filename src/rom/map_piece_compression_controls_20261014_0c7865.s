.setcpu "65816"
.segment "CODE"
.org $7865
map_control_0c7865:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
