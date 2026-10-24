.setcpu "65816"
.segment "CODE"
.org $97D6
map_control_0e97d6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
