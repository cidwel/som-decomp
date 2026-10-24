.setcpu "65816"
.segment "CODE"
.org $86EB
map_control_0f86eb:
    .byte $E1 ; previous-row copy count
