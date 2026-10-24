.setcpu "65816"
.segment "CODE"
.org $EDDC
map_control_0deddc:
    .byte $E1 ; previous-row copy count
