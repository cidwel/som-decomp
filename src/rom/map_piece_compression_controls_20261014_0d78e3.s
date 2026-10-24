.setcpu "65816"
.segment "CODE"
.org $78E3
map_control_0d78e3:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
