.setcpu "65816"
.segment "CODE"
.org $FFA9
map_control_0dffa9:
    .byte $E1 ; previous-row copy count
