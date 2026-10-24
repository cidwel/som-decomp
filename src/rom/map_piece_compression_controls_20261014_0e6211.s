.setcpu "65816"
.segment "CODE"
.org $6211
map_control_0e6211:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C7 ; same-value copy count/distance
