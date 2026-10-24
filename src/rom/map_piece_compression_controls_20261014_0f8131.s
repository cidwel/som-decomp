.setcpu "65816"
.segment "CODE"
.org $8131
map_control_0f8131:
    .byte $E3 ; previous-row copy count
