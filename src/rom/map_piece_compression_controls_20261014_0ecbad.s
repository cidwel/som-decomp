.setcpu "65816"
.segment "CODE"
.org $CBAD
map_control_0ecbad:
    .byte $E4 ; previous-row copy count
