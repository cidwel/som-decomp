.setcpu "65816"
.segment "CODE"
.org $86BF
map_control_0f86bf:
    .byte $E7 ; previous-row copy count
