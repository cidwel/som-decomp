.setcpu "65816"
.segment "CODE"
.org $BB23
map_control_0fbb23:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
