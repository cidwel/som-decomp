.setcpu "65816"
.segment "CODE"
.org $CC25
map_control_0fcc25:
    .byte $E3 ; previous-row copy count
