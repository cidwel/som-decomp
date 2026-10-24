.setcpu "65816"
.segment "CODE"
.org $E59A
map_control_0de59a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
