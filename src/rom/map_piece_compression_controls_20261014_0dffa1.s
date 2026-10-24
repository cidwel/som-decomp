.setcpu "65816"
.segment "CODE"
.org $FFA1
map_control_0dffa1:
    .byte $E4 ; previous-row copy count
