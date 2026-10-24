.setcpu "65816"
.segment "CODE"
.org $B0FB
map_control_0eb0fb:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
