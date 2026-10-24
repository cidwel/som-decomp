.setcpu "65816"
.segment "CODE"
.org $BCED
map_control_0dbced:
    .byte $E1 ; previous-row copy count
