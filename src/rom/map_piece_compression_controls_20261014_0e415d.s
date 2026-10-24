.setcpu "65816"
.segment "CODE"
.org $415D
map_control_0e415d:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
