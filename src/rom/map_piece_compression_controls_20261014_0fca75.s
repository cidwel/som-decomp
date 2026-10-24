.setcpu "65816"
.segment "CODE"
.org $CA75
map_control_0fca75:
    .byte $E4 ; previous-row copy count
