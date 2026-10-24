.setcpu "65816"
.segment "CODE"
.org $0F23
map_control_0c0f23:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
