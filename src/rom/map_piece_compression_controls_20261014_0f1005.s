.setcpu "65816"
.segment "CODE"
.org $1005
map_control_0f1005:
    .byte $E3 ; previous-row copy count
