.setcpu "65816"
.segment "CODE"
.org $F7EC
map_control_0df7ec:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
