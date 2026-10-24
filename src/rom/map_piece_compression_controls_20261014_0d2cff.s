.setcpu "65816"
.segment "CODE"
.org $2CFF
map_control_0d2cff:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
