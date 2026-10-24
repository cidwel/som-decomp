.setcpu "65816"
.segment "CODE"
.org $2B3E
map_control_0f2b3e:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
