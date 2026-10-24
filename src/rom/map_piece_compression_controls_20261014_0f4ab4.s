.setcpu "65816"
.segment "CODE"
.org $4AB4
map_control_0f4ab4:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
