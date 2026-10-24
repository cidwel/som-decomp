.setcpu "65816"
.segment "CODE"
.org $65F3
map_control_0f65f3:
    .byte $E1 ; previous-row copy count
