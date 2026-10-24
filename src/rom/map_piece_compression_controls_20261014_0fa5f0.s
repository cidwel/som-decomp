.setcpu "65816"
.segment "CODE"
.org $A5F0
map_control_0fa5f0:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
