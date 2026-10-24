.setcpu "65816"
.segment "CODE"
.org $DA1B
map_control_0eda1b:
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
