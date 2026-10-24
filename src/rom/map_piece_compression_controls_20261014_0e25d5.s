.setcpu "65816"
.segment "CODE"
.org $25D5
map_control_0e25d5:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $F4 ; progressive-copy count
    .byte $E7 ; previous-row copy count
