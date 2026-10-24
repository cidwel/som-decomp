.setcpu "65816"
.segment "CODE"
.org $800D
map_control_0e800d:
    .byte $E1 ; previous-row copy count
