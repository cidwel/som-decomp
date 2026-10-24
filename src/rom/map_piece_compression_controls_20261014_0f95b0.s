.setcpu "65816"
.segment "CODE"
.org $95B0
map_control_0f95b0:
    .byte $E2 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
