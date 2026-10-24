.setcpu "65816"
.segment "CODE"
.org $BA9D
map_control_0fba9d:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
