.setcpu "65816"
.segment "CODE"
.org $78ED
map_control_0f78ed:
    .byte $E1 ; previous-row copy count
