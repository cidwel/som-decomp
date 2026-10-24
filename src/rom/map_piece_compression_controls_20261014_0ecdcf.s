.setcpu "65816"
.segment "CODE"
.org $CDCF
map_control_0ecdcf:
    .byte $E2 ; previous-row copy count
