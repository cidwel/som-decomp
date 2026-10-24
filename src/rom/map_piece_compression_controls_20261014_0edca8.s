.setcpu "65816"
.segment "CODE"
.org $DCA8
map_control_0edca8:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
