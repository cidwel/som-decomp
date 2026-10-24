.setcpu "65816"
.segment "CODE"
.org $4BE3
map_control_0d4be3:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
