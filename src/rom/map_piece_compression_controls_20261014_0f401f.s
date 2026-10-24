.setcpu "65816"
.segment "CODE"
.org $401F
map_control_0f401f:
    .byte $E3 ; previous-row copy count
