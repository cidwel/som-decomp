.setcpu "65816"
.segment "CODE"
.org $A5E4
map_control_0fa5e4:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
