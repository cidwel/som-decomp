.setcpu "65816"
.segment "CODE"
.org $7B72
map_control_0d7b72:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
