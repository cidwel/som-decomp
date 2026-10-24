.setcpu "65816"
.segment "CODE"
.org $ACCB
map_control_0faccb:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
