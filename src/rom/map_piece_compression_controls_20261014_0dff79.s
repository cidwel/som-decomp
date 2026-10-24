.setcpu "65816"
.segment "CODE"
.org $FF79
map_control_0dff79:
    .byte $E6 ; previous-row copy count
