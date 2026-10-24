.setcpu "65816"
.segment "CODE"
.org $0FB4
map_control_0f0fb4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
