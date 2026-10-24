.setcpu "65816"
.segment "CODE"
.org $F6BA
map_control_0ef6ba:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $39 ; distance low bit/count
