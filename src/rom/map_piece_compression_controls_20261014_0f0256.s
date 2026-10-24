.setcpu "65816"
.segment "CODE"
.org $0256
map_control_0f0256:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
