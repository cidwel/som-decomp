.setcpu "65816"
.segment "CODE"
.org $3EFA
map_control_0d3efa:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
