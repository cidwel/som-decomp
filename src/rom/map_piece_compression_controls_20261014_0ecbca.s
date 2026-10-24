.setcpu "65816"
.segment "CODE"
.org $CBCA
map_control_0ecbca:
    .byte $E6 ; previous-row copy count
