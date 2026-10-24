.setcpu "65816"
.segment "CODE"
.org $1ACC
map_control_0c1acc:
    .byte $E3 ; previous-row copy count
