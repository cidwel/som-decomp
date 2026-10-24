.setcpu "65816"
.segment "CODE"
.org $4206
map_control_0f4206:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
