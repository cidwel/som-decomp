.setcpu "65816"
.segment "CODE"
.org $1BBC
map_control_0e1bbc:
    .byte $E1 ; previous-row copy count
