.setcpu "65816"
.segment "CODE"
.org $B9FF
map_control_0fb9ff:
    .byte $E0 ; previous-row copy escape
    .byte $6D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6A ; row-distance/count
