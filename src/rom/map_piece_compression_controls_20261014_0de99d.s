.setcpu "65816"
.segment "CODE"
.org $E99D
map_control_0de99d:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
