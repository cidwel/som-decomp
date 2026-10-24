.setcpu "65816"
.segment "CODE"
.org $CBEE
map_control_0dcbee:
    .byte $E1 ; previous-row copy count
