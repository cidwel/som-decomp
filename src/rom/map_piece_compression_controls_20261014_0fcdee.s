.setcpu "65816"
.segment "CODE"
.org $CDEE
map_control_0fcdee:
    .byte $E1 ; previous-row copy count
