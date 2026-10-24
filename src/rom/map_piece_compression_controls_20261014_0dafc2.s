.setcpu "65816"
.segment "CODE"
.org $AFC2
map_control_0dafc2:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
