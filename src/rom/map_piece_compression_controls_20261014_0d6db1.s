.setcpu "65816"
.segment "CODE"
.org $6DB1
map_control_0d6db1:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
