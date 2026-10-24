.setcpu "65816"
.segment "CODE"
.org $0861
map_control_0e0861:
    .byte $F2 ; progressive-copy count
    .byte $E6 ; previous-row copy count
