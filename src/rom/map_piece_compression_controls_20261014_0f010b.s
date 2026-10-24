.setcpu "65816"
.segment "CODE"
.org $010B
map_control_0f010b:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C9 ; same-value copy count/distance
