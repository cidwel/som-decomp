.setcpu "65816"
.segment "CODE"
.org $34FD
map_control_0f34fd:
    .byte $E1 ; previous-row copy count
