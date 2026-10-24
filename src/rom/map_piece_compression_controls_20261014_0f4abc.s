.setcpu "65816"
.segment "CODE"
.org $4ABC
map_control_0f4abc:
    .byte $E2 ; previous-row copy count
