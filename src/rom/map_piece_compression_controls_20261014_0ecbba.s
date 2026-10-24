.setcpu "65816"
.segment "CODE"
.org $CBBA
map_control_0ecbba:
    .byte $E4 ; previous-row copy count
