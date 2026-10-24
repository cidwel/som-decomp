.setcpu "65816"
.segment "CODE"
.org $DACC
map_control_0edacc:
    .byte $E1 ; previous-row copy count
