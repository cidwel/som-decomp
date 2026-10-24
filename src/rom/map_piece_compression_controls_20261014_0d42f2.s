.setcpu "65816"
.segment "CODE"
.org $42F2
map_control_0d42f2:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
