.setcpu "65816"
.segment "CODE"
.org $9BA6
map_control_0e9ba6:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
