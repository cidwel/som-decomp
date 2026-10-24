.setcpu "65816"
.segment "CODE"
.org $C08F
map_control_0fc08f:
    .byte $E1 ; previous-row copy count
