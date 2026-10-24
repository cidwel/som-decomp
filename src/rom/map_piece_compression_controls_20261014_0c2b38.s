.setcpu "65816"
.segment "CODE"
.org $2B38
map_control_0c2b38:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
