.setcpu "65816"
.segment "CODE"
.org $25A7
map_control_0e25a7:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
