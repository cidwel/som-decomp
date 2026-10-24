.setcpu "65816"
.segment "CODE"
.org $8AF8
map_control_0d8af8:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
