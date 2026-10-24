.setcpu "65816"
.segment "CODE"
.org $E52B
map_control_0fe52b:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E4 ; previous-row copy count
