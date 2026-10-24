.setcpu "65816"
.segment "CODE"
.org $F435
map_control_0df435:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $CF ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
