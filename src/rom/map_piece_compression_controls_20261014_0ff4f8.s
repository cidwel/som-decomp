.setcpu "65816"
.segment "CODE"
.org $F4F8
map_control_0ff4f8:
    .byte $E1 ; previous-row copy count
