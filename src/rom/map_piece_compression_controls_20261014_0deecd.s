.setcpu "65816"
.segment "CODE"
.org $EECD
map_control_0deecd:
    .byte $E1 ; previous-row copy count
