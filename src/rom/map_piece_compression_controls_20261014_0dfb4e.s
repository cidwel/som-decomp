.setcpu "65816"
.segment "CODE"
.org $FB4E
map_control_0dfb4e:
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
