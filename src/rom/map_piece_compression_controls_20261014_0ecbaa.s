.setcpu "65816"
.segment "CODE"
.org $CBAA
map_control_0ecbaa:
    .byte $E1 ; previous-row copy count
