.setcpu "65816"
.segment "CODE"
.org $56BF
map_control_0f56bf:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
