.setcpu "65816"
.segment "CODE"
.org $06CC
map_control_0f06cc:
    .byte $D9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
