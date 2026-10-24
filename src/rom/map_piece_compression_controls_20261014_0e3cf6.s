.setcpu "65816"
.segment "CODE"
.org $3CF6
map_control_0e3cf6:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
