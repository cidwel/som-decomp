.setcpu "65816"
.segment "CODE"
.org $0A1C
map_control_0e0a1c:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
