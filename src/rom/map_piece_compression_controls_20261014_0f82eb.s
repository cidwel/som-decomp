.setcpu "65816"
.segment "CODE"
.org $82EB
map_control_0f82eb:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
