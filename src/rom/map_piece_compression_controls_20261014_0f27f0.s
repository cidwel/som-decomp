.setcpu "65816"
.segment "CODE"
.org $27F0
map_control_0f27f0:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
