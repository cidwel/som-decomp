.setcpu "65816"
.segment "CODE"
.org $AE79
map_control_0fae79:
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $CA ; same-value copy count/distance
