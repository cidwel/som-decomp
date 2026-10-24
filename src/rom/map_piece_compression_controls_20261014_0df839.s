.setcpu "65816"
.segment "CODE"
.org $F839
map_control_0df839:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
