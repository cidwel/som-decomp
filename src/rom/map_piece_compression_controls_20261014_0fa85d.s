.setcpu "65816"
.segment "CODE"
.org $A85D
map_control_0fa85d:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
