.setcpu "65816"
.segment "CODE"
.org $D010
map_control_0fd010:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
