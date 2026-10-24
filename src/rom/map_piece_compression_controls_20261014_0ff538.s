.setcpu "65816"
.segment "CODE"
.org $F538
map_control_0ff538:
    .byte $E1 ; previous-row copy count
