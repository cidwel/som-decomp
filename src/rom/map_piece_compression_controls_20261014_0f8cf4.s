.setcpu "65816"
.segment "CODE"
.org $8CF4
map_control_0f8cf4:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
