.setcpu "65816"
.segment "CODE"
.org $86CC
map_control_0e86cc:
    .byte $E5 ; previous-row copy count
