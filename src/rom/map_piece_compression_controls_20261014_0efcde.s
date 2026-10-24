.setcpu "65816"
.segment "CODE"
.org $FCDE
map_control_0efcde:
    .byte $E5 ; previous-row copy count
