.setcpu "65816"
.segment "CODE"
.org $5F32
map_control_0d5f32:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
