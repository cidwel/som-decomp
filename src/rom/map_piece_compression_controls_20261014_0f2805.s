.setcpu "65816"
.segment "CODE"
.org $2805
map_control_0f2805:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
