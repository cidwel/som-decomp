.setcpu "65816"
.segment "CODE"
.org $CEFE
map_control_0ecefe:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
