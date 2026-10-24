.setcpu "65816"
.segment "CODE"
.org $C09A
map_control_0fc09a:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
