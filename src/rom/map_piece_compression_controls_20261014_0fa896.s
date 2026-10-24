.setcpu "65816"
.segment "CODE"
.org $A896
map_control_0fa896:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
