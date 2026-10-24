.setcpu "65816"
.segment "CODE"
.org $2CC5
map_control_0f2cc5:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
