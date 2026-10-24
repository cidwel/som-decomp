.setcpu "65816"
.segment "CODE"
.org $8AFB
map_control_0d8afb:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
