.setcpu "65816"
.segment "CODE"
.org $AF8A
map_control_0daf8a:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
