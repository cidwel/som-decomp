.setcpu "65816"
.segment "CODE"
.org $A250
map_control_0fa250:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
