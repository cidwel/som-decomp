.setcpu "65816"
.segment "CODE"
.org $DFCE
map_control_0ddfce:
    .byte $E1 ; previous-row copy count
