.setcpu "65816"
.segment "CODE"
.org $CDDB
map_control_0fcddb:
    .byte $E1 ; previous-row copy count
