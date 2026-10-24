.setcpu "65816"
.segment "CODE"
.org $27DE
map_control_0f27de:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
