.setcpu "65816"
.segment "CODE"
.org $F4EE
map_control_0ff4ee:
    .byte $E1 ; previous-row copy count
