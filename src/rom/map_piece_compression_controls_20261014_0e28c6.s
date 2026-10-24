.setcpu "65816"
.segment "CODE"
.org $28C6
map_control_0e28c6:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
