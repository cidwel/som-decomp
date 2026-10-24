.setcpu "65816"
.segment "CODE"
.org $AFCB
map_control_0eafcb:
    .byte $E1 ; previous-row copy count
