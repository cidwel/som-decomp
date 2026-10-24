.setcpu "65816"
.segment "CODE"
.org $ACEE
map_control_0eacee:
    .byte $E2 ; previous-row copy count
