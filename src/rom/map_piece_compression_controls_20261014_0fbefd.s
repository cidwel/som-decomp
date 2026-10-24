.setcpu "65816"
.segment "CODE"
.org $BEFD
map_control_0fbefd:
    .byte $E2 ; previous-row copy count
