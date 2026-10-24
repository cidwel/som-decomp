.setcpu "65816"
.segment "CODE"
.org $36FA
map_control_0c36fa:
    .byte $F3 ; progressive-copy count
    .byte $E1 ; previous-row copy count
