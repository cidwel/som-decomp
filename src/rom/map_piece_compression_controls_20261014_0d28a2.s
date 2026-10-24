.setcpu "65816"
.segment "CODE"
.org $28A2
map_control_0d28a2:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
