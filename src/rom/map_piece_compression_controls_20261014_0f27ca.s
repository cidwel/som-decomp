.setcpu "65816"
.segment "CODE"
.org $27CA
map_control_0f27ca:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
