.setcpu "65816"
.segment "CODE"
.org $E2F8
map_control_0fe2f8:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
