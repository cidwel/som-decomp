.setcpu "65816"
.segment "CODE"
.org $7214
map_control_0f7214:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
