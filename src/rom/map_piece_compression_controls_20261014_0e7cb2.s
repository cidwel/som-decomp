.setcpu "65816"
.segment "CODE"
.org $7CB2
map_control_0e7cb2:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
