.setcpu "65816"
.segment "CODE"
.org $F826
map_control_0ff826:
    .byte $E7 ; previous-row copy count
