.setcpu "65816"
.segment "CODE"
.org $902C
map_control_0d902c:
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
