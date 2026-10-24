.setcpu "65816"
.segment "CODE"
.org $8FA1
map_control_0f8fa1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
