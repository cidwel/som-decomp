.setcpu "65816"
.segment "CODE"
.org $74AF
map_control_0d74af:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C5 ; same-value copy count/distance
