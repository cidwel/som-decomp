.setcpu "65816"
.segment "CODE"
.org $EEFD
map_control_0deefd:
    .byte $E1 ; previous-row copy count
