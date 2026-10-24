.setcpu "65816"
.segment "CODE"
.org $EF99
map_control_0fef99:
    .byte $E1 ; previous-row copy count
