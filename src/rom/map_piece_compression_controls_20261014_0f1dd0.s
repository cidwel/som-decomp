.setcpu "65816"
.segment "CODE"
.org $1DD0
map_control_0f1dd0:
    .byte $E5 ; previous-row copy count
