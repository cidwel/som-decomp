.setcpu "65816"
.segment "CODE"
.org $FF37
map_control_0dff37:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
