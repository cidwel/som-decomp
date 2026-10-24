.setcpu "65816"
.segment "CODE"
.org $CC5E
map_control_0ecc5e:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
