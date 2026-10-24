.setcpu "65816"
.segment "CODE"
.org $F6A0
map_control_0ff6a0:
    .byte $E6 ; previous-row copy count
