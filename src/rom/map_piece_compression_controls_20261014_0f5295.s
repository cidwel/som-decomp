.setcpu "65816"
.segment "CODE"
.org $5295
map_control_0f5295:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
