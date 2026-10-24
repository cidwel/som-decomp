.setcpu "65816"
.segment "CODE"
.org $CA13
map_control_0fca13:
    .byte $E5 ; previous-row copy count
