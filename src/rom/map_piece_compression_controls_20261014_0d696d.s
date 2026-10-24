.setcpu "65816"
.segment "CODE"
.org $696D
map_control_0d696d:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
