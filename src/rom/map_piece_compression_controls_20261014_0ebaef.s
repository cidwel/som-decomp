.setcpu "65816"
.segment "CODE"
.org $BAEF
map_control_0ebaef:
    .byte $E1 ; previous-row copy count
