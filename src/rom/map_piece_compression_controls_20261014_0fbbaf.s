.setcpu "65816"
.segment "CODE"
.org $BBAF
map_control_0fbbaf:
    .byte $E5 ; previous-row copy count
