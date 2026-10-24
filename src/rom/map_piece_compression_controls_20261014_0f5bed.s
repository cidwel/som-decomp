.setcpu "65816"
.segment "CODE"
.org $5BED
map_control_0f5bed:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
