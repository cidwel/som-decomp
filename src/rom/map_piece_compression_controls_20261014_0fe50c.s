.setcpu "65816"
.segment "CODE"
.org $E50C
map_control_0fe50c:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E5 ; previous-row copy count
