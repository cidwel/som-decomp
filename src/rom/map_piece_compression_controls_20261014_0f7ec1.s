.setcpu "65816"
.segment "CODE"
.org $7EC1
map_control_0f7ec1:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
