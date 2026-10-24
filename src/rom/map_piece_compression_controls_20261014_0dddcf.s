.setcpu "65816"
.segment "CODE"
.org $DDCF
map_control_0dddcf:
    .byte $E3 ; previous-row copy count
