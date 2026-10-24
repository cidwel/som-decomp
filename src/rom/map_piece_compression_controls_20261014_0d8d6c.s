.setcpu "65816"
.segment "CODE"
.org $8D6C
map_control_0d8d6c:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
