.setcpu "65816"
.segment "CODE"
.org $2866
map_control_0d2866:
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
