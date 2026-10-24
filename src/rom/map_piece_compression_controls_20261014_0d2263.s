.setcpu "65816"
.segment "CODE"
.org $2263
map_control_0d2263:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $CC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
