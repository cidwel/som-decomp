.setcpu "65816"
.segment "CODE"
.org $F1DF
map_control_0ef1df:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
