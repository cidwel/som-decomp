.setcpu "65816"
.segment "CODE"
.org $345E
map_control_0f345e:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
