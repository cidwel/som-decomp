.setcpu "65816"
.segment "CODE"
.org $2111
map_control_0f2111:
    .byte $E3 ; previous-row copy count
