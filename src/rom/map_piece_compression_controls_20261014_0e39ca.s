.setcpu "65816"
.segment "CODE"
.org $39CA
map_control_0e39ca:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
