.setcpu "65816"
.segment "CODE"
.org $F543
map_control_0ff543:
    .byte $E5 ; previous-row copy count
