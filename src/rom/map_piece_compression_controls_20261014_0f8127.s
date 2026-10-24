.setcpu "65816"
.segment "CODE"
.org $8127
map_control_0f8127:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
