.setcpu "65816"
.segment "CODE"
.org $FA10
map_control_0efa10:
    .byte $E3 ; previous-row copy count
