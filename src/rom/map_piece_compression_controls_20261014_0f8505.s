.setcpu "65816"
.segment "CODE"
.org $8505
map_control_0f8505:
    .byte $E3 ; previous-row copy count
