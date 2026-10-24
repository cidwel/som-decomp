.setcpu "65816"
.segment "CODE"
.org $FECC
map_control_0efecc:
    .byte $E1 ; previous-row copy count
