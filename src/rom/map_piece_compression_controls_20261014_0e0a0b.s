.setcpu "65816"
.segment "CODE"
.org $0A0B
map_control_0e0a0b:
    .byte $F2 ; progressive-copy count
    .byte $E6 ; previous-row copy count
