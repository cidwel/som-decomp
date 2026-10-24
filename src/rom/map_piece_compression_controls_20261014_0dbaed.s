.setcpu "65816"
.segment "CODE"
.org $BAED
map_control_0dbaed:
    .byte $E4 ; previous-row copy count
