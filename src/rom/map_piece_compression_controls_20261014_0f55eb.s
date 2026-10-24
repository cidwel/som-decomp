.setcpu "65816"
.segment "CODE"
.org $55EB
map_control_0f55eb:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
