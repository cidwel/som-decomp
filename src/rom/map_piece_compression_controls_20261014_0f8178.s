.setcpu "65816"
.segment "CODE"
.org $8178
map_control_0f8178:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
