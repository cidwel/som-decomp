.setcpu "65816"
.segment "CODE"
.org $64FD
map_control_0c64fd:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $C3 ; same-value copy count/distance
