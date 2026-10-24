.setcpu "65816"
.segment "CODE"
.org $FFDB
map_control_0dffdb:
    .byte $E2 ; previous-row copy count
