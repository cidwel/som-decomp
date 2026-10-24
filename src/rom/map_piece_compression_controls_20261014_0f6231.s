.setcpu "65816"
.segment "CODE"
.org $6231
map_control_0f6231:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $CD ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
