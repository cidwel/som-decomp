.setcpu "65816"
.segment "CODE"
.org $A638
map_control_0fa638:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
