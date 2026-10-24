.setcpu "65816"
.segment "CODE"
.org $A483
map_control_0fa483:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
