.setcpu "65816"
.segment "CODE"
.org $F10A
map_control_0ff10a:
    .byte $E1 ; previous-row copy count
