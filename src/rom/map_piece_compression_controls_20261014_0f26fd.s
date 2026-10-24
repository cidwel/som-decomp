.setcpu "65816"
.segment "CODE"
.org $26FD
map_control_0f26fd:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
