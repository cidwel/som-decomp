.setcpu "65816"
.segment "CODE"
.org $6A14
map_control_0d6a14:
    .byte $CC ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
