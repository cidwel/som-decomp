.setcpu "65816"
.segment "CODE"
.org $ACEB
map_control_0faceb:
    .byte $E3 ; previous-row copy count
