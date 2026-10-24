.setcpu "65816"
.segment "CODE"
.org $3B80
map_control_0e3b80:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
