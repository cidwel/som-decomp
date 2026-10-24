.setcpu "65816"
.segment "CODE"
.org $E1AF
map_control_0de1af:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
