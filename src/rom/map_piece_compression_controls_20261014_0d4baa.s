.setcpu "65816"
.segment "CODE"
.org $4BAA
map_control_0d4baa:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $C3 ; same-value copy count/distance
