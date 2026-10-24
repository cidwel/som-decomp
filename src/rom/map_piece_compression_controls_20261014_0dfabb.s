.setcpu "65816"
.segment "CODE"
.org $FABB
map_control_0dfabb:
    .byte $E1 ; previous-row copy count
