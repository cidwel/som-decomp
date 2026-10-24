.setcpu "65816"
.segment "CODE"
.org $CB96
map_control_0ecb96:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
