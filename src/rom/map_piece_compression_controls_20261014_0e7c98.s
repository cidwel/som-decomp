.setcpu "65816"
.segment "CODE"
.org $7C98
map_control_0e7c98:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
