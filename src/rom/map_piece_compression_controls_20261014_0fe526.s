.setcpu "65816"
.segment "CODE"
.org $E526
map_control_0fe526:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E5 ; previous-row copy count
