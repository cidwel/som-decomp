.setcpu "65816"
.segment "CODE"
.org $83A3
map_control_0c83a3:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
