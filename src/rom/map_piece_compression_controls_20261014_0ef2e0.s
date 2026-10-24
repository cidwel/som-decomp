.setcpu "65816"
.segment "CODE"
.org $F2E0
map_control_0ef2e0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C5 ; same-value copy count/distance
