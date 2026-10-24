.setcpu "65816"
.segment "CODE"
.org $0D6D
map_control_0f0d6d:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
