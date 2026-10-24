.setcpu "65816"
.segment "CODE"
.org $A84B
map_control_0fa84b:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
