.setcpu "65816"
.segment "CODE"
.org $CDFD
map_control_0fcdfd:
    .byte $E5 ; previous-row copy count
