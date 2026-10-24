.setcpu "65816"
.segment "CODE"
.org $25E5
map_control_0e25e5:
    .byte $E2 ; previous-row copy count
    .byte $F4 ; progressive-copy count
