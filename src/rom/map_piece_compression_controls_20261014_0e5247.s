.setcpu "65816"
.segment "CODE"
.org $5247
map_control_0e5247:
    .byte $D9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
