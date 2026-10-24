.setcpu "65816"
.segment "CODE"
.org $4C99
map_control_0f4c99:
    .byte $CF ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
