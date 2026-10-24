.setcpu "65816"
.segment "CODE"
.org $84A0
map_control_0d84a0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C5 ; same-value copy count/distance
