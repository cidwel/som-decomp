.setcpu "65816"
.segment "CODE"
.org $6C77
map_control_0f6c77:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $CF ; same-value copy count/distance
