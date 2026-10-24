.setcpu "65816"
.segment "CODE"
.org $060B
map_control_0e060b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
