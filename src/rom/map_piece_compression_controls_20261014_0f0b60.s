.setcpu "65816"
.segment "CODE"
.org $0B60
map_control_0f0b60:
    .byte $E7 ; previous-row copy count
