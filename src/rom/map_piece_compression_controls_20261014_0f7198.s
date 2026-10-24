.setcpu "65816"
.segment "CODE"
.org $7198
map_control_0f7198:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
