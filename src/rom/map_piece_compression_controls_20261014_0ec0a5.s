.setcpu "65816"
.segment "CODE"
.org $C0A5
map_control_0ec0a5:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
