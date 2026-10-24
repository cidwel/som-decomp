.setcpu "65816"
.segment "CODE"
.org $FC1F
map_control_0ffc1f:
    .byte $E4 ; previous-row copy count
