.setcpu "65816"
.segment "CODE"
.org $0FCA
map_control_0e0fca:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
