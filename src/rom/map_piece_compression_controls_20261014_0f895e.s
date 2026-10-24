.setcpu "65816"
.segment "CODE"
.org $895E
map_control_0f895e:
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
