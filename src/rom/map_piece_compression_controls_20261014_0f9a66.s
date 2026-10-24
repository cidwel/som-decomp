.setcpu "65816"
.segment "CODE"
.org $9A66
map_control_0f9a66:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C3 ; same-value copy count/distance
