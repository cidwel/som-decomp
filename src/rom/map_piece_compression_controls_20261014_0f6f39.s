.setcpu "65816"
.segment "CODE"
.org $6F39
map_control_0f6f39:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E4 ; previous-row copy count
