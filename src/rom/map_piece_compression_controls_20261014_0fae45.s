.setcpu "65816"
.segment "CODE"
.org $AE45
map_control_0fae45:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $CD ; same-value copy count/distance
