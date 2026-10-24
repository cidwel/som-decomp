.setcpu "65816"
.segment "CODE"
.org $AD22
map_control_0ead22:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
