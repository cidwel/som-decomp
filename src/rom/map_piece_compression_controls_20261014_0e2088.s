.setcpu "65816"
.segment "CODE"
.org $2088
map_control_0e2088:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6A ; row-distance/count
