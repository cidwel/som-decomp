.setcpu "65816"
.segment "CODE"
.org $28D5
map_control_0e28d5:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
