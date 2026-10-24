.setcpu "65816"
.segment "CODE"
.org $1018
map_control_0f1018:
    .byte $E1 ; previous-row copy count
