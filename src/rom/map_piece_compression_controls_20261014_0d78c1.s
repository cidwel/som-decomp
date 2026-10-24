.setcpu "65816"
.segment "CODE"
.org $78C1
map_control_0d78c1:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
