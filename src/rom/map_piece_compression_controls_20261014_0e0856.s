.setcpu "65816"
.segment "CODE"
.org $0856
map_control_0e0856:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
