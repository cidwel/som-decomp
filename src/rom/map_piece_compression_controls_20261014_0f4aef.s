.setcpu "65816"
.segment "CODE"
.org $4AEF
map_control_0f4aef:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
