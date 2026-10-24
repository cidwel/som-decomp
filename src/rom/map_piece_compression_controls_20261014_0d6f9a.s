.setcpu "65816"
.segment "CODE"
.org $6F9A
map_control_0d6f9a:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E6 ; previous-row copy count
