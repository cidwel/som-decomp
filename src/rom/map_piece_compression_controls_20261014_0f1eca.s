.setcpu "65816"
.segment "CODE"
.org $1ECA
map_control_0f1eca:
    .byte $E1 ; previous-row copy count
