.setcpu "65816"
.segment "CODE"
.org $8CBC
map_control_0f8cbc:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
