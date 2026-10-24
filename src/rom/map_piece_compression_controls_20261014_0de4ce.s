.setcpu "65816"
.segment "CODE"
.org $E4CE
map_control_0de4ce:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
