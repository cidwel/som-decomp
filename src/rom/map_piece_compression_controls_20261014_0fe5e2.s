.setcpu "65816"
.segment "CODE"
.org $E5E2
map_control_0fe5e2:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
