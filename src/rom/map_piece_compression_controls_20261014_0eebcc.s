.setcpu "65816"
.segment "CODE"
.org $EBCC
map_control_0eebcc:
    .byte $E1 ; previous-row copy count
