.setcpu "65816"
.segment "CODE"
.org $6744
map_control_0d6744:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
