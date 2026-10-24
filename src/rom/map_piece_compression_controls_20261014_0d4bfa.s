.setcpu "65816"
.segment "CODE"
.org $4BFA
map_control_0d4bfa:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
