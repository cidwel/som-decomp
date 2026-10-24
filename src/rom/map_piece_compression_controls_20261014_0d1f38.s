.setcpu "65816"
.segment "CODE"
.org $1F38
map_control_0d1f38:
    .byte $E5 ; previous-row copy count
