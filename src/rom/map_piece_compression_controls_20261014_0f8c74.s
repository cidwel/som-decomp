.setcpu "65816"
.segment "CODE"
.org $8C74
map_control_0f8c74:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
