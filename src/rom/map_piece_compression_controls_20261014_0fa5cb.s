.setcpu "65816"
.segment "CODE"
.org $A5CB
map_control_0fa5cb:
    .byte $E1 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
