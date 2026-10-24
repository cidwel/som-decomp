.setcpu "65816"
.segment "CODE"
.org $05BF
map_control_0f05bf:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
