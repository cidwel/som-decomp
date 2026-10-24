.setcpu "65816"
.segment "CODE"
.org $1519
map_control_0c1519:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
